# Open Orbis Toolchain Dockerfile

## Synopsis

The Open Orbis team has put together a Dockerfile to make compiling PKGs with the Open Orbis PS4 Toolchain trivial to do. This makes updating the toolchain simple, stops the environment from becoming contaminated (or contaminating another environment), minimizes the troubleshooting needed for issues, enables building with a particular version, etc. This document is aimed at providing an overview of how to use the Dockerfile to make a developer's life easier. There are multiple methods that can be utilized depending on the developer's individual need at any given time.

## Methods

The most common use case for each method is as follows:

- [Single Line Build]: You are building a PKG file on your local machine.
- [Github Actions]: Used to check pull requests, generate releases, etc on Github without needing user interaction.
- [CLI Access]: Testing, debugging, etc.

### Single Line Build

Windows:

```shell
docker run -w /workspace -v "%cd%":/workspace openorbis/toolchain:latest make
```

Linux/OSX/BSD:

```shell
docker run -w /workspace -v "$(pwd)":/workspace openorbis/toolchain:latest make
```

This one-liner will run the `make` command from your current working directory as if it were on a machine with the latest Open Orbis Toolchain installed and working as expected. You can use this to launch a custom script as necessary. See the [Build Script] section for some caveats.

### Github Actions

The following action will use the Open Orbis Toolchain v0.5 to run `make` in the project's `hello_world` directory, then use `PkgTool.Core pkg_build pkg/pkg.gp4 .` to build a PKG file.

```yml
- name: Run Open Orbis Toolchain
        uses: OpenOrbis/toolchain-action@main
        with:
          version: v0.5
          command: cd hello_world; make; PkgTool.Core pkg_build pkg/pkg.gp4 .
```

You could also run the [Build Script] `action.sh` from the project's root directory with the latest Open Orbis Toolchain release with the following action:

```yml
- name: Run Open Orbis Toolchain
        uses: OpenOrbis/toolchain-action@main
        with:
          version: latest
          command: bash action.sh
```

### CLI Access

You can open an interactive shell within the container with the following command:

Windows:

```shell
docker run -it --entrypoint=/bin/bash -v "%cd%":/workspace openorbis/toolchain
```

Linux/OSX/BSD:

```shell
docker run -it --entrypoint=/bin/bash -v "$(pwd)":/workspace openorbis/toolchain
```

**Note:** In the above commands only changes made in the `/workspace` directory will remain as it is the mounted directory and is actually on the host machine.

## Docker Requirement

To use the "[CLI Access]" and "[Single Line Build]" method you must have [Docker] installed locally.

### Building Docker Image

When manually building a Docker image based on the Dockerfile you must specify the version of the toolcahin to build for with `--build-arg OO_TOOLCHAIN_VERSION=` ex. `docker build -t "ootoolchain:v0.5" . --build-arg OO_TOOLCHAIN_VERSION=v0.5`

## Build Script

Some notes to keep in mind:

- This is a minimal Ubuntu 20.04  installation. You'll need to install other applications as necessary
- The working directory will be the repo's root directory
- Use relative paths for locations within the repo's directory
- **ANY error should stop the Github Action immediately**

## Other Tips

- It is possible to specify why Toolchain version to use by specifying the version in the commands. ex. `openorbis/toolchain:v0.5`, you can also use `latest` to use the most recent build.
- `docker pull openorbis/toolchain` will update your Docker container to the latest release or `docker pull openorbis/toolchain:v0.5` to pull a specific version's update.
- Always pull the new container's data before deleting old containers as there may be overlap/cached data and will save you download time

## Docker Development

The development of the Dockerfile and this document file can be found [here](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/). This repo uses Github Actions to build and publish the Docker container to Docker Hub automatically on releases. The workflow file can be found [here](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/tree/master/.github/workflows/docker.yml). The Github Action for the toolchain can be found [here](https://github.com/OpenOrbis/toolchain-action).

## Additional Support

Additional support will be provided in the [Open Orbis Discord] server.

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [Synopsis]: <#synopsis>
   [Methods]: <#methods>
   [Single Line Build]: <#single-line-build>
   [Github Actions]: <#github-actions>
   [CLI Access]: <#cli-access>
   [Docker Requirement]: <#docker-requirement>
   [Building Docker Image]: <#building-docker-image>
   [Build Script]: <#build-script>
   [Other Tips]: <#other-tips>
   [Docker Development]: <#docker-development>
   [Additional Support]: <#additional-support>

   [Docker]: <https://www.docker.com/>
   [Open Orbis Discord]: <https://discord.com/invite/GQr8ydn>
