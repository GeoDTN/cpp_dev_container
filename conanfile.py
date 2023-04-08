from conans import ConanFile, CMake, tools

class cpp_project_Conan(ConanFile):
    license = ""
    url = ""
    description = ""

    settings = "os", "compiler", "build_type", "arch"
    requires = ""

    options = {"shared": [True, False]}
    default_options = "shared=False"

    generators = "cmake"

    def package(self):
        self.copy( "*", "", "install" )
        
    def package_info(self):
        self.cpp_info.libs = ["cpp_project"]