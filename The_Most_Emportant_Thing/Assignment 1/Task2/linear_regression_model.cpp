// This program implements simple and multiple linear regression using the normal equation and gradient descent, and exports the generated data to a CSV file.

#include <iostream> // includes commands to print code
#include <vector> // will be used to define vectors x, y 
#include <fstream> // library to eventually export cvs file
#include <random> //used to add noise to linear regression so it is more realistic

int main () {
    const int slope= 3, k=4, points= 100 ; //initalising slope, y-int & number of random points. these are the TRUE parameters
    std::vector<double> x;
    std::vector<double> y;

    //set up the noise 
    std::random_device rd; //get randomised number
    std::mt19937 gen(rd()); //initialise Mersenne Twister
    std::normal_distribution<double> dist_noise(0.0, 0.4); //mean of 0 so noise doesn't disturb data trend- standard deviation = 0.4 so noise is not too large to distort the data trend but enough to make it more realistic
    std::uniform_real_distribution<double> dist_x(0.0, 100.0); //// uniformly distributes x values across [0, 100] to give a representative range of inputs

    for(int i=0; i < points; ++i){
        double temporary_x = dist_x(gen); //temporary x & y used to hold values generated in each iteration to be then stored
        double noise = dist_noise(gen); //generates random noise for each point
        double temporary_y = (k * temporary_x) + slope + noise; // y= kx + m + noise

        //store values at the end of the defined vectors using push_back
         x.push_back(temporary_x);
         y.push_back(temporary_y);

        }

    //find mean of x for normal equation
    double sum_x= 0;
    for(int i = 0; i < x.size(); ++i){
        sum_x = sum_x + x[i];
    }
    double mean_x = sum_x / x.size();
    // find mean of y for normal equation 
    double sum_y= 0;
    for(int i=0; i<y.size(); ++i){
        sum_y = sum_y + y[i];
    }
    double mean_y = sum_y / y.size();

    // this next section calculates w

    // numerator and denominator initialised of the normal equation for w
    double numerator = 0;
    double denominator = 0;

    for (int i = 0; i < x.size(); ++i) {
         double dx = x[i] - mean_x;
         double dy = y[i] - mean_y;
         numerator   += dx * dy;   // // accumulate running total of (x[i]-mean_x)(y[i]-mean_y) across all points
         denominator += dx * dx;   // add up (x[i]-mean_x)^2
    }

    double w = numerator / denominator;
    double b = mean_y - w * mean_x;
    
    //gradient descent 

    double w_gd = 0.0;  // initialise w & b for gradient descent
    double b_gd = 0.0;
    double eta = 0.00001;       // learning rate, changed through trial and error
    int iterations = 1000000;   // how many steps to take, changed through trial and error. matched to learning rate so it can converge

    for (int iter = 0; iter < iterations; ++iter) { 
        // reset gradients each iteration before accumulating over all points
         double grad_w_gd = 0.0;
         double grad_b_gd = 0.0;

    // loop over all data points and accumulate grad_w and grad_b
    // grad_w += (w*x[i] + b - y[i]) * x[i]
    // grad_b += (w*x[i] + b - y[i])
    for (int i = 0; i < x.size(); ++i) {
        double error = w_gd * x[i] + b_gd - y[i]; // whats the error at point i
        grad_w_gd += error * x[i];  // accumulate error for w
        grad_b_gd += error;          // accumulate error for b
    }

    grad_w_gd = grad_w_gd / points;  // divide by number of points
    grad_b_gd = grad_b_gd / points;
   //updated values for w & b
    w_gd -= eta * grad_w_gd;
    b_gd -= eta * grad_b_gd;
}

// Multiple linear regression, vectors 
std::vector<double> x1;
std::vector<double> x2;

// set up variables for  y = w1*x1 + w2*x2 + b
std::vector<double> y_mlr; //mlr-> multiple linear regression
//THESE ARE THE TRUE VALUES WE COMPARE AGAINST
const double w1 = 3.0; 
const double w2 = 2.0;
const double b_mlr  = 5.0; // b for multiple linear regression
// the noise has already been set up earlier in the loop just apply it to both x1 and x2
for(int i=0; i < points; ++i){
    double temporary_x1 = dist_x(gen); //temporary x & y used to hold values generated in each iteration to be then stored
    double temporary_x2 = dist_x(gen);
    double noise = dist_noise(gen); //generates random noise
    double temporary_y1 = w1 * temporary_x1 + w2*temporary_x2 + b_mlr + noise ;

        //store values at the end of the defined vectors using push_back
    x1.push_back(temporary_x1);
    x2.push_back(temporary_x2);
    y_mlr.push_back(temporary_y1);

}

// gradient descent for multiple linear regression
//initialise two w (multiple linear regression) and b
    double w1_gd = 0.0;  // two w given multiple linear regression
    double w2_gd = 0.0;
    double b_mlr_gd = 0.0; 

    // reset gradients for both weights and bias each iteration
    for (int iter = 0; iter < iterations; ++iter) {
         double grad_w1_gd = 0.0;
         double grad_w2_gd = 0.0;
         double grad_b_mlr_gd = 0.0;

    // loop over all data points and accumulate grad_w1, grad_w2 and grad_b_mlr
    for (int i = 0; i < x1.size(); ++i) {
        double error = w1_gd * x1[i] + w2_gd * x2[i] + b_mlr_gd - y_mlr[i]; // whats the error at point i
        grad_w1_gd += error * x1[i];  // accumulate error for w1
        grad_w2_gd += error * x2[i];  // accumulate error for w2
        grad_b_mlr_gd += error;          // accumulate error for b
    }

    grad_w1_gd = grad_w1_gd / points;  // divide by number of points
    grad_w2_gd = grad_w2_gd / points;  
    grad_b_mlr_gd = grad_b_mlr_gd / points;
   //updated values for w and b
    w1_gd -= eta * grad_w1_gd;
    w2_gd -= eta * grad_w2_gd;
    b_mlr_gd -= eta * grad_b_mlr_gd;
}

// output all the equations
std::cout << "Normal Equation:  w = " << w << ", b = " << b << "\n";
std::cout << "Gradient Descent: w = " << w_gd << ", b = " << b_gd << "\n";
std::cout << "True values:      w = " << k << ", b = " << slope << "\n";
std::cout << "Multiple Linear Regression Gradient Descent: w1 = " << w1_gd << ", w2 = " << w2_gd << ", b = " << b_mlr_gd << "\n";
std::cout << "Multiple Linear Regression True values:      w1 = " << w1 << ", w2 = " << w2 << ", b = " << b_mlr << "\n";

//output CVS file for plotting on python
std::ofstream file("task2_assignment1_ap3.csv");
file << "x,y\n"; // header row
for (int i = 0; i < x.size(); ++i) {
    file << x[i] << "," << y[i] << "\n"; // write each point on a new line
}
file.close();

}
