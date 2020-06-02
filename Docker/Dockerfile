FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y clang lld git build-essential wget python
    
ENV OO_PS4_TOOLCHAIN=/lib/open-orbis

RUN mkdir /lib/open-orbis && \
    git clone https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain.git $OO_PS4_TOOLCHAIN/ && \
    mkdir -p $OO_PS4_TOOLCHAIN/bin/linux

RUN wget https://dl.google.com/go/go1.14.2.linux-amd64.tar.gz -O /tmp/go.tar.gz && \
    tar -xvf /tmp/go.tar.gz -C /usr/local/

ENV GOROOT=/usr/local/go
ENV GOPATH=$HOME/go
ENV PATH=$GOPATH/bin:$GOROOT/bin:$PATH

RUN cd $OO_PS4_TOOLCHAIN/src/tools/create-eboot/ && bash build.sh
RUN cd $OO_PS4_TOOLCHAIN/src/tools/readelf/ && bash build.sh

RUN cd $OO_PS4_TOOLCHAIN/src/tools/orbisLibGen/ && \
    git clone https://github.com/idc/ps4libdoc.git && cd ps4libdoc/ && git checkout 5.05
RUN cd $OO_PS4_TOOLCHAIN/src/tools/orbisLibGen/ && \
    python generate.py ps4libdoc/ && \
    python gen_makefile.py && \
    cd build && make