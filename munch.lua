-- munchhausen
-- A Munchausen number is a natural number n the sum of whose digits (in base 10),
-- each raised to the power of itself, equals n.
--
-- (Munchausen is also spelled: Münchhausen.)
-- For instance:   3435 = 3^3 + 4^4 + 3^3 + 5^5

local pwr = {}
for i = 0,9 do
  pwr[i] = i^i
end

local function is_munchhausen(i)
  local sum = 0
  local n = i

  while n > 0 do
    local digit = n % 10
    sum = sum + pwr[digit]
    n = n // 10
  end

  if i == sum then
    return true
  end

  return false
end

for i = 1,1e7 do
  if is_munchhausen(i) then
    print(i)
  end
end
