{ pkgs ? (import <nixpkgs> {}) }:
with pkgs;

mkShell {
  
  buildInputs = [
    cmake
    gcc
    glslang
    pkg-config
    #xorg.libXau
    xorg.libxcb
    vulkan-headers
    vulkan-loader
    vulkan-tools
    vulkan-validation-layers
  ];

  # If it doesn’t get picked up through nix magic
  VULKAN_SDK = "${vulkan-validation-layers}/share/vulkan/explicit_layer.d";
}