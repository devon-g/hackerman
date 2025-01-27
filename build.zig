const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Hack executable
    const hack = b.addExecutable(.{
        .name = "hack",
        .target = target,
        .optimize = optimize,
    });
    hack.addCSourceFiles(.{
        .files = &.{
            "src/hack.c",
            "src/mem.c",
            "src/proc.c",
        },
        .flags = &.{
            "-g",
            "-Wall",
            "-Werror",
        },
    });

    // Dummy executable
    const dummy = b.addExecutable(.{
        .name = "dummy",
        .target = target,
        .optimize = optimize, 
    });
    dummy.addCSourceFile(.{
        .file = b.path("src/dummy.c"),
        .flags = &.{
            "-g",
            "-Wall",
            "-Werror",
        },
    });


    // Link c libs
    hack.linkLibC();
    dummy.linkLibC();

    // Create build step for each exe
    const hack_step = b.step("hack", "Build hack");
    const dummy_step = b.step("dummy", "Build dummy");

    // Install the binaries to prefix
    const install_hack = b.addInstallArtifact(hack, .{});
    const install_dummy = b.addInstallArtifact(dummy, .{});

    // zig build hack or dummy will install hack or dummy
    hack_step.dependOn(&install_hack.step);
    dummy_step.dependOn(&install_dummy.step);

    // zig build will install both exes
    b.getInstallStep().dependOn(&install_hack.step);
    b.getInstallStep().dependOn(&install_dummy.step);

    // TODO: figure out how to make zig build uninstall work properly
}
