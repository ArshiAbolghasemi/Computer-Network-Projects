FROM ubuntu:22.04

ENV CONTAINER_DIR=/computer_network
WORKDIR ${CONTAINER_DIR}

RUN apt-get update && apt-get -y upgrade && \
    apt-get --no-install-recommends -y install \
        build-essential \
    && apt-get clean

COPY . ${CONTAINER_DIR}

VOLUME /os

CMD ["-m", "512"]