# BASE STAGE: Minimal install for what is required for the SDK to run
FROM alpine:3.12.0 AS base

# Install needed applications for running the SDK
RUN apk update && \
    apk add --no-cache \
        build-base=0.5-r2 \
        clang=10.0.0-r2 \
        lld=10.0.0-r0

# SETUP STAGE: Minimal install for what is required to download/setup the SDK
FROM alpine:3.12.0 as setup

# Install needed applications for downloading/setting up the SDK
RUN apk update && \
    apk add --no-cache \
        curl=7.69.1-r1 \
        tar=1.32-r1

# Set the OO_PS4_TOOLCHAIN environmental variable for later use vs using copy/paste
ENV OO_PS4_TOOLCHAIN=/lib/OpenOrbisSDK

# Set repo and version from CLI input
ARG GITHUB_REPOSITORY
ARG OO_TOOLCHAIN_VERSION

# Download the latest Linux release and extract to the $OO_PS4_TOOLCHAIN directory
SHELL ["/bin/ash", "-eo", "pipefail", "-c"]
RUN mkdir -p $OO_PS4_TOOLCHAIN/ && \
    curl -sL https://github.com/$GITHUB_REPOSITORY/releases/download/$OO_TOOLCHAIN_VERSION/$OO_TOOLCHAIN_VERSION.tar.gz | \
    tar -xz -C $OO_PS4_TOOLCHAIN/ bin/data bin/linux include lib scripts LICENSE link.x

# RUNTIME STAGE: The final stage where the magic happens
FROM base as runtime

# Set the environmental variables for the SDK location
ENV OO_PS4_TOOLCHAIN=/lib/OpenOrbisSDK
ENV PATH=$OO_PS4_TOOLCHAIN:$OO_PS4_TOOLCHAIN/bin:$PATH

# Set version from CLI input
ARG OO_TOOLCHAIN_VERSION
ENV OO_TOOLCHAIN_VERSION $OO_TOOLCHAIN_VERSION

# Copy the SDK from the setup stage to this stage
COPY --from=setup ${OO_PS4_TOOLCHAIN} ${OO_PS4_TOOLCHAIN}
