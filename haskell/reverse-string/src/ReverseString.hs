module ReverseString (reverseString) where

reverseString :: String -> String
reverseString = reverse

revStr :: String -> String
revStr str = if length str == 0 || length str == 1 then str else (last str) : (revStr (init str))
