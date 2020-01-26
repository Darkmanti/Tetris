@echo off
pushd %~dp0
cd ..\src\
IF NOT EXIST src.sln ( COPY /V ..\misc\VS_config\src.sln src.sln) ELSE ( COPY /V src.sln ..\misc\VS_config\src.sln)
IF NOT EXIST src.vcxproj ( COPY /V ..\misc\VS_config\src.vcxproj src.vcxproj) ELSE ( COPY /V src.vcxproj ..\misc\VS_config\src.vcxproj)
IF NOT EXIST src.vcxproj.filters ( COPY /V ..\misc\VS_config\src.vcxproj.filters src.vcxproj.filters) ELSE ( COPY /V src.vcxproj.filters ..\misc\VS_config\src.vcxproj.filters)
IF NOT EXIST src.vcxproj.user ( COPY /V ..\misc\VS_config\src.vcxproj.user src.vcxproj.user) ELSE ( COPY /V src.vcxproj.user ..\misc\VS_config\src.vcxproj.user)
popd