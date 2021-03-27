# munchhausen
# A Munchausen number is a natural number n the sum of whose digits (in base 10),
# each raised to the power of itself, equals n.

# (Munchausen is also spelled: Münchhausen.)
# For instance:   3435 = 3^3 + 4^4 + 3^3 + 5^5


require 'benchmark'
require_relative 'munch'


PWR = (0..10).map { |i| i ** i }

def vanilla_is_munchhausen(i)
  sum = 0
  n = i
  while n > 0
    d = n % 10
    sum += PWR[d]
    n /= 10
  end

  return i == sum
end


Benchmark.bm do |bm|
  include Munch

  bm.report("vanilla:") {
    (1..1e7.to_i).each do |i|
      if vanilla_is_munchhausen(i)
        # found
      end
    end
  }

  bm.report("native:") {
    (1..1e7.to_i).each do |i|
      if is_munch(i)
        # found
      end
    end
  }
end
