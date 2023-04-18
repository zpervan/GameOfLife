workspace(name = "GameOfLife")

local_repository(
    name = "bazel_skylib",
    path = "ThirdParty/BazelSkylib/",
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

# -------- PYTHON DEPENDENCIES (GTest) --------

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_python",
    sha256 = "a644da969b6824cc87f8fe7b18101a8a6c57da5db39caa6566ec6109f37d2141",
    strip_prefix = "rules_python-0.20.0",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.20.0/rules_python-0.20.0.tar.gz",
)

load("@rules_python//python:repositories.bzl", "py_repositories")

py_repositories()

local_repository(
    name = "fmtlib",
    path = "ThirdParty/fmt/",
)

local_repository(
    name = "gllib",
    path = "ThirdParty/GL/",
)

local_repository(
    name = "googletestlib",
    path = "ThirdParty/googletest/",
)

local_repository(
    name = "imguilib",
    path = "ThirdParty/imgui/",
)

local_repository(
    name = "sfmllib",
    path = "ThirdParty/SFML/",
)
