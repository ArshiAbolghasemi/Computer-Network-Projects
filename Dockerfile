FROM ubuntu:22.04

ENV CONTAINER_DIR=/computer_network
WORKDIR ${CONTAINER_DIR}

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y upgrade && \
    apt-get --no-install-recommends -y install \
        build-essential \
        # wget \
    && apt-get clean

    # RUN wget https://github.com/LoopPerfect/buckaroo/releases/download/v2.2.0/buckaroo-linux --no-check-certificate -O buckaroo && \
    #     chmod +x ./buckaroo && \
    # ./buckaroo 

COPY . ${CONTAINER_DIR}

VOLUME ${CONTAINER_DIR}

CMD ["-m", "512"]