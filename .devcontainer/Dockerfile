FROM debian:bookworm

# Add some extra dependencies for use in a devcontainer context.
RUN apt-get update
ADD tools/requirements-debian.txt /tools/requirements-debian.txt
RUN apt-get install -y $(cat /tools/requirements-debian.txt)

# Add a default non-root user.
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

USER $USERNAME
