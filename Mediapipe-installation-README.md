Mediapipe c++ installation

1. Install Bazel/bazelisk

1.1. Install the necessary dependencies by running the following command:

	sudo apt-get install pkg-config zip g++ zlib1g-dev unzip python

1.2. Download the Bazelisk binary by running the following command:

	wget https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64

This will download the latest release of Bazelisk for Linux on x86-64 architecture.

1.3. Rename the downloaded binary to bazel and move it to /usr/local/bin directory:

	mv bazelisk-linux-amd64 /usr/local/bin/bazel

1.4. Make the binary executable by running the following command:

	chmod +x /usr/local/bin/bazel

1.5. Verify that Bazel is installed correctly by running the following command:

	bazel version

This should print the version of Bazel installed on your system.

2. checkout MediaPipe repo
	cd
	git clone --depth=1 https://github.com/google/mediapipe.git
	cd mediapipe
3. install opencv	
open setup_opencv.sh (vim or sth)

find on line 43  libdc1394-22-dev change it to  libdc1394-dev

	chmod +x setup_opencv.sh

	./setup_opencv.sh

also make sure you already have installed python and numpy

	sudo apt update
	sudo apt install python3-pip
	pip install numpy

4. Run the Hello World! 
	
	export GLOG_logtostderr=1
	bazel run --define MEDIAPIPE_DISABLE_GPU=1 \
    mediapipe/examples/desktop/hello_world:hello_world

# Should print:
# Hello World!
# Hello World!
# Hello World!
# Hello World!
# Hello World!
# Hello World!
# Hello World!
# Hello World!
# Hello World!
# Hello World! 

also these are helpful links

	https://google.github.io/mediapipe/getting_started/cpp#option-1-running-on-cpu

	there are some tfile files are missing in mediapipe repo so here the link to dwnld from

https://github.com/google/mediapipe/blob/abfcd8ec1dfc54631f083405f8d4f0972adba839/docs/solutions/models.md


