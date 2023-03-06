CONTAINER_NAME ?= ut/computer-network
CONTAINER_WORKDIR ?= /computer_network

build:
	docker build -t ${CONTAINER_NAME} .

bash:
	docker run -v $(pwd):${CONTAINER_WORKDIR} -it ${CONTAINER_NAME} /bin/bash