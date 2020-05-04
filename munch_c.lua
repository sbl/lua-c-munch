-- c library
local mu = require("mu")


for i = 1,1e7 do
  if mu.is_munch(i) then
    print(i)
  end
end
