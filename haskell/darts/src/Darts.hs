module Darts (score) where

score :: Float -> Float -> Int
score x y
  | inCircle 1 = 10
  | inCircle 5 = 5
  | inCircle 10 = 1
  | otherwise = 0
  where
    inCircle r = (x * x) + (y * y) <= r * r
