# sudo docker run -ti -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --name dev conradbzura/blackbox:dev-v0

FROM ubuntu:14.04

# Install applications
RUN apt-get update && \
    apt-get install -y \
        software-properties-common \
        git \
        vim-gtk \
        build-essential \
        clang-3.6 \
        llvm \
	libc++-dev

# Configure git
RUN git config --global user.email "conradbzura@gmail.com" && \
    git config --global user.name "Conrad Bzura" && \
    git config --global push.default matching

# Install window theme
RUN apt-add-repository ppa:numix/ppa && \
    apt-get update && \
    apt-get install -y \
        numix-gtk-theme

# Configure user
# Replace 1000 with your user / group id
RUN export uid=1000 gid=1000 && \
    mkdir -p /home/developer && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer

USER developer
ENV HOME /home/developer
ENTRYPOINT ["/bin/bash"]

