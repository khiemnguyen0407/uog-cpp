--[[
  ENG3091 Quarto filter.

  Program output (```{.text .output}) and terminal sessions
  (```{.text .terminal}) are not source code, so they never get line numbers.
]]
function CodeBlock(el)
  if el.classes:includes("output") or el.classes:includes("terminal") then
    el.attributes["code-line-numbers"] = "false"
    return el
  end
end
