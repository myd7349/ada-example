mkdir build-x86-windows-static-md
pushd build-x86-windows-static-md
cmake .. -DCMAKE_TOOLCHAIN_FILE="%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake" -DVCPKG_TARGET_TRIPLET=x86-windows-static-md -DCMAKE_GENERATOR_PLATFORM=Win32
cmake --build . --config Release
pushd Release
for /F %%x in ('dir /A:-D /B *.exe') do (
  set FILENAME=%%x
  echo ===========================  Run %%x ===========================
  %%x
)
popd
popd
pause
