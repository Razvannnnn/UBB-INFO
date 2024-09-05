# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeProject1 "CosProduse.cpp CosProduse.h Error.h LabRepo.cpp main.cpp produs.cpp repo.cpp repo.h service.cpp service.h test_vector.cpp ui.cpp ui.h undo.h validare.cpp validare.h vector.cpp vector.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
