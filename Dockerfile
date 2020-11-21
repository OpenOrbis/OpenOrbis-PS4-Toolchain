# BASE STAGE: Minimal install for what is required for the SDK to run
FROM ubuntu:20.04 AS base

ENV DEBIAN_FRONTEND=noninteractive

# Install needed applications for running the SDK
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      build-essential=12.8ubuntu1 \
      clang=1:10.0-50~exp1 \
      libicu66=66.1-2ubuntu2 \
      libssl1.1=1.1.1f-1ubuntu2 \
      lld=1:10.0-50~exp1 && \
    rm -rf /var/lib/apt/lists/*

# SETUP STAGE: Minimal install for what is required to download/setup the SDK
FROM ubuntu:20.04 as setup

# Install needed applications for downloading/setting up the SDK
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      ca-certificates \
      curl=7.68.0-1ubuntu2.2 \
      tar=1.30+dfsg-7 && \
    rm -rf /var/lib/apt/lists/*

# Set the OO_PS4_TOOLCHAIN environmental variable for later use vs using copy/paste
ENV OO_PS4_TOOLCHAIN=/lib/OpenOrbisSDK

# Set repo and version from CLI input
ARG OO_TOOLCHAIN_VERSION

# Download the latest Linux release and extract to the $OO_PS4_TOOLCHAIN directory
SHELL ["/bin/bash", "-o", "pipefail", "-c"]
RUN mkdir -p $OO_PS4_TOOLCHAIN/ && \
    curl -L https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/releases/download/$OO_TOOLCHAIN_VERSION/$OO_TOOLCHAIN_VERSION.tar.gz | \
    tar -xz -C $OO_PS4_TOOLCHAIN bin/data bin/linux include lib scripts LICENSE link.x

# RUNTIME STAGE: The final stage where the magic happens
FROM base as runtime

# Set the environmental variables for the SDK location
ENV OO_PS4_TOOLCHAIN=/lib/OpenOrbisSDK
ENV PATH=$OO_PS4_TOOLCHAIN:$OO_PS4_TOOLCHAIN/bin/linux:$PATH

# Set version from CLI input
ARG OO_TOOLCHAIN_VERSION
ENV OO_TOOLCHAIN_VERSION=$OO_TOOLCHAIN_VERSION

# Copy the SDK from the setup stage to this stage
COPY --from=setup ${OO_PS4_TOOLCHAIN} ${OO_PS4_TOOLCHAIN}

# Create non-root user to use by default
RUN groupadd -g 1000 orbis && \
    useradd -r -u 1000 -g orbis orbis
USER orbis
