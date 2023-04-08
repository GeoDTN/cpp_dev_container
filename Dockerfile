
FROM ubuntu:22.04

# LABEL about the custom image
LABEL maintainer="tadewos85@gmail.com"
LABEL version="0.0.0.1"
LABEL description="This is a custom Docker Image for tests and project in modern C++."

ARG   INFO_PROJECT=""
ARG   INFO_VERSION=""
ARG   INFO_BRANCH=""
ARG   INFO_COMMIT=""
ARG   INFO_NAMESPACE=""
ARG   INFO_URL=""

LABEL Info.Project="$INFO_PROJECT"
LABEL Info.Version="$INFO_VERSION"
LABEL Info.Branch="$INFO_BRANCH"
LABEL Info.Commit="$INFO_COMMIT"
LABEL Info.Namespace="$INFO_NAMESPACE"
LABEL Info.Url="$INFO_URL"
COPY build/00001  /home/${USER}/cpp/
WORKDIR /home/${USER}/cpp/

ENTRYPOINT ["./00001"]
