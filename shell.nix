{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShellNoCC {
  name = "tictactoe-dev";

  nativeBuildInputs = with pkgs; [
    cmake
    gnumake
    gcc
    clang-tools # provides clang-format
    gdb # for debugging
  ];

  buildInputs = with pkgs; [
    ncurses
  ];

  shellHook = ''
    echo "Nix enviroment for tictactoe is ready!"
  '';
}
