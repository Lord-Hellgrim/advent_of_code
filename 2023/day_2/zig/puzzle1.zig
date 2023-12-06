const std = @import("std");

pub fn main() !void {

    const file = try std.fs.cwd().openFile("puzzle_input.txt", .{});
    defer file.close();

    const allocator = std.heap.page_allocator;
    const contents: []u8 = try file.readToEndAlloc(allocator, 1000000); // Adjust max size as needed
    defer allocator.free(contents);

    const token = std.mem.splitAny(u8, contents, "\n");
    std.debug.print("{s}", .{token});

    // Use the contents here
    // std.debug.print("File contents: {s}\n", .{contents});

    

}