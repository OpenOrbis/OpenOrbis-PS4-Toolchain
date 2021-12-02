### Setup build env
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND "noninteractive"
ENV TZ "America/New_York"

RUN apt-get update && \
	apt-get install -y git build-essential cmake ninja-build python3-distutils \
	wget tar libncurses5 unzip

RUN mkdir llvm && mkdir ps4

### Install LLVM10 prebuilts
RUN wget https://github.com/llvm/llvm-project/releases/download/llvmorg-10.0.0/clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz && tar -xf clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz -C llvm --strip-components=1 && rm clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz

### Install go 1.15.3
RUN wget https://golang.org/dl/go1.15.13.linux-amd64.tar.gz && rm -rf /usr/local/go && tar -C /usr/local -xzf go1.15.13.linux-amd64.tar.gz

### Set path and other env variables
ENV PATH "$PATH:/llvm/bin:/usr/local/go/bin"
ENV OO_PS4_TOOLCHAIN "/OpenOrbis-PS4-Toolchain"

COPY build.sh /build.sh

ENTRYPOINT ["/build.sh"]
