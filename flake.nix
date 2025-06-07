{
  inputs = {
    # nixpkgs.url = "github:cachix/devenv-nixpkgs/rolling";
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    systems.url = "github:nix-systems/default";
    devenv = {
      url = "github:cachix/devenv";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  nixConfig = {
    extra-trusted-public-keys = "devenv.cachix.org-1:w1cLUi8dv3hnoSPGAuibQv+f9TZLr6cv/Hm9XgU50cw=";
    extra-substituters = "https://devenv.cachix.org";
  };

  outputs = {
    self,
    nixpkgs,
    devenv,
    systems,
    ...
  } @ inputs: let
    forEachSystem = nixpkgs.lib.genAttrs (import systems);
  in {
    packages = forEachSystem (system: {
      devenv-up = self.devShells.${system}.default.config.procfileScript;
      devenv-test = self.devShells.${system}.default.config.test;
    });

    devShells =
      forEachSystem
      (system: let
        pkgs = nixpkgs.legacyPackages.${system};

        ffmpeg = "${pkgs.ffmpeg}/bin/ffmpeg";
      in {
        default = devenv.lib.mkShell {
          inherit inputs pkgs;
          modules = [
            {
              # https://devenv.sh/reference/options/
              packages = with pkgs; [
                # build dependencies
                clang
                pkg-config

                ## X11
                xorg.libX11.dev
                xorg.libXext
                libbsd

                # dev tools
                norminette
                # lldb

                (
                  pkgs.writers.writeBashBin
                  "convert"
                  {}
                  /*
                  bash
                  */
                  ''
                    for file in ./output/*.bmp; do
                    	printf "\033[1m$file\033[0m ->";
                    	${ffmpeg} -i "$file" -c:v png "''${file%.bmp}.png" -y -v 0
                    	printf " \033[1;32m''${file%.bmp}.png\033[0m\n";
                    done
                  ''
                )
              ];

              env = {
                X11_INCLUDE_PATH = "${pkgs.xorg.libX11.dev}/include";
                X11_EXT_INCLUDE_PATH = "${pkgs.xorg.libXext.dev}/include";
              };

              languages.c = {
                enable = true;
              };

              git-hooks.hooks = let
                norminetteWrapper =
                  pkgs.writers.writeBashBin "norminette"
                  /*
                  bash
                  */
                  ''
                    ${pkgs.norminette}/bin/norminette "$@" | ${pkgs.ripgrep}/bin/rg -q '^Error:' && exit 1 || exit 0
                  '';
                norminette = "${norminetteWrapper}/bin/norminette";
              in {
                norminette = {
                  enable = true;
                  name = "norminette";

                  entry = norminette;
                  files = "\\.(c|h)$";

                  stages = [
                    "pre-commit"
                  ];
                };

                norminette-global = {
                  enable = true;
                  name = "norminette-global";

                  entry = norminette;
                  args = ["./src" "./inc"];
                  pass_filenames = false;
                  always_run = true;

                  stages = [
                    "pre-push"
                  ];
                };

                build = {
                  enable = true;
                  name = "build";

                  entry = "make";
                  pass_filenames = false;
                  always_run = true;

                  stages = [
                    "pre-commit"
                    "pre-push"
                  ];
                };

                checkmake = {
                  enable = true;
                  stages = ["pre-commit" "pre-push"];
                };
              };
            }
          ];
        };
      });
  };
}
