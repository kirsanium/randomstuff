cmake_minimum_required(VERSION 3.10)
project(Task1_psv)

set(CMAKE_CXX_STANDARD 11)

file(GLOB ROOT_SOURCE ./*.cpp)
file(GLOB ROOT_INLINE ./*.inl)
file(GLOB ROOT_HEADER ./*.hpp)
file(GLOB ROOT_TEXT *.txt)
file(GLOB ROOT_MD *.md)
file(GLOB ROOT_NAT util/glm.natvis)

file(GLOB_RECURSE CORE_SOURCE ./glm/detail/*.cpp)
file(GLOB_RECURSE CORE_INLINE ./glm/detail/*.inl)
file(GLOB_RECURSE CORE_HEADER ./glm/detail/*.hpp)

file(GLOB_RECURSE GTC_SOURCE ./glm/gtc/*.cpp)
file(GLOB_RECURSE GTC_INLINE ./glm/gtc/*.inl)
file(GLOB_RECURSE GTC_HEADER ./glm/gtc/*.hpp)

file(GLOB_RECURSE GTX_SOURCE ./glm/gtx/*.cpp)
file(GLOB_RECURSE GTX_INLINE ./glm/gtx/*.inl)
file(GLOB_RECURSE GTX_HEADER ./glm/gtx/*.hpp)

file(GLOB_RECURSE SIMD_SOURCE ./glm/simd/*.cpp)
file(GLOB_RECURSE SIMD_INLINE ./glm/simd/*.inl)
file(GLOB_RECURSE SIMD_HEADER ./glm/simd/*.h)

source_group("Text Files" FILES ${ROOT_TEXT} ${ROOT_MD})
source_group("Core Files" FILES ${CORE_SOURCE})
source_group("Core Files" FILES ${CORE_INLINE})
source_group("Core Files" FILES ${CORE_HEADER})
source_group("GTC Files" FILES ${GTC_SOURCE})
source_group("GTC Files" FILES ${GTC_INLINE})
source_group("GTC Files" FILES ${GTC_HEADER})
source_group("GTX Files" FILES ${GTX_SOURCE})
source_group("GTX Files" FILES ${GTX_INLINE})
source_group("GTX Files" FILES ${GTX_HEADER})
source_group("SIMD Files" FILES ${SIMD_SOURCE})
source_group("SIMD Files" FILES ${SIMD_INLINE})
source_group("SIMD Files" FILES ${SIMD_HEADER})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(GLM_STATIC_LIBRARY_ENABLE OR GLM_DYNAMIC_LIBRARY_ENABLE)
    if(GLM_STATIC_LIBRARY_ENABLE)
        add_library(glm_static STATIC ${ROOT_TEXT} ${ROOT_MD} ${ROOT_NAT}
                ${ROOT_SOURCE}    ${ROOT_INLINE}    ${ROOT_HEADER}
                ${CORE_SOURCE}    ${CORE_INLINE}    ${CORE_HEADER}
                ${GTC_SOURCE}     ${GTC_INLINE}     ${GTC_HEADER}
                ${GTX_SOURCE}     ${GTX_INLINE}     ${GTX_HEADER}
                ${SIMD_SOURCE}    ${SIMD_INLINE}    ${SIMD_HEADER})
    endif(GLM_STATIC_LIBRARY_ENABLE)

    if(GLM_DYNAMIC_LIBRARY_ENABLE)
        add_library(glm_shared SHARED ${ROOT_TEXT} ${ROOT_MD} ${ROOT_NAT}
                ${ROOT_SOURCE}    ${ROOT_INLINE}    ${ROOT_HEADER}
                ${CORE_SOURCE}    ${CORE_INLINE}    ${CORE_HEADER}
                ${GTC_SOURCE}     ${GTC_INLINE}     ${GTC_HEADER}
                ${GTX_SOURCE}     ${GTX_INLINE}     ${GTX_HEADER}
                ${SIMD_SOURCE}    ${SIMD_INLINE}    ${SIMD_HEADER})
    endif(GLM_DYNAMIC_LIBRARY_ENABLE)

else(GLM_STATIC_LIBRARY_ENABLE OR GLM_DYNAMIC_LIBRARY_ENABLE)
    add_executable(glm_dummy ${ROOT_TEXT} ${ROOT_MD} ${ROOT_NAT}
            ${ROOT_SOURCE}    ${ROOT_INLINE}    ${ROOT_HEADER}
            ${CORE_SOURCE}    ${CORE_INLINE}    ${CORE_HEADER}
            ${GTC_SOURCE}     ${GTC_INLINE}     ${GTC_HEADER}
            ${GTX_SOURCE}     ${GTX_INLINE}     ${GTX_HEADER}
            ${SIMD_SOURCE}    ${SIMD_INLINE}    ${SIMD_HEADER})

endif(GLM_STATIC_LIBRARY_ENABLE OR GLM_DYNAMIC_LIBRARY_ENABLE)

add_executable(Task1_psv main.cpp)
link_directories(./lib)
#target_link_libraries(Task1_psv Opengl32 GL GLU glut)
target_link_libraries(Task1_psv freeglut)