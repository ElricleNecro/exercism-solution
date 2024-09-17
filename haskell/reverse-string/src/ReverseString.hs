module ReverseString (reverseString) where

reverseString :: String -> String
reverseString str = if length str == 0 then str else if length str == 1 then [str !! 0] else reverseString (tail str) ++ [head str]
