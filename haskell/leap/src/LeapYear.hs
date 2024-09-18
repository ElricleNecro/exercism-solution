module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
isLeapYear year
  | divisibleBy 4 && not(divisibleBy 100) = True
  | divisibleBy 400 = True
  | otherwise = False
  where
    divisibleBy d = year `mod` d == 0
