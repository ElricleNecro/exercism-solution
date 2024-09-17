const std = @import("std");

pub fn isArmstrongNumber(num: u128) bool {
    if( num == 0 ) {
        return true;
    }

    const length: u128 = @intFromFloat(std.math.floor(@as(f64, @floatFromInt(std.math.log10(num))) + 1.0));
    var sum: u128 = 0;
    var value = num;

    while (value > 0) {
        sum += std.math.pow(u128, value % 10, length);
        value /= 10;
    }

    return sum == num;
}
