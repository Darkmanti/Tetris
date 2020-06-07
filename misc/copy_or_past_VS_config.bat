@echo off
pushd %~dp0
cd ..\src\
IF NOT EXIST src.sln ( COPY /V ..\misc\VS_config\src\src.sln src.sln) ELSE ( COPY /V src.sln ..\misc\VS_config\src\src.sln)
IF NOT EXIST src.vcxproj ( COPY /V ..\misc\VS_config\src\src.vcxproj src.vcxproj) ELSE ( COPY /V src.vcxproj ..\misc\VS_config\src\src.vcxproj)
IF NOT EXIST src.vcxproj.filters ( COPY /V ..\misc\VS_config\src\src.vcxproj.filters src.vcxproj.filters) ELSE ( COPY /V src.vcxproj.filters ..\misc\VS_config\src\src.vcxproj.filters)
IF NOT EXIST src.vcxproj.user ( COPY /V ..\misc\VS_config\src\src.vcxproj.user src.vcxproj.user) ELSE ( COPY /V src.vcxproj.user ..\misc\VS_config\src\src.vcxproj.user)
popd
REM nextStageofCopy
pushd %~dp0
set miscMetaEnumDir=VS_config\MetaEnumGen\
set srcMetaEnumDir=..\..\..\meta\MetaEnumGen\MetaEnum\
cd %miscMetaEnumDir%
IF NOT EXIST %srcMetaEnumDir%MetaEnum.sln ( COPY /V MetaEnum.sln %srcMetaEnumDir%MetaEnum.sln) ELSE ( COPY /V %srcMetaEnumDir%MetaEnum.sln MetaEnum.sln )
IF NOT EXIST %srcMetaEnumDir%MetaEnum.vcxproj ( COPY /V MetaEnum.vcxproj %srcMetaEnumDir%MetaEnum.vcxproj) ELSE ( COPY /V %srcMetaEnumDir%MetaEnum.vcxproj MetaEnum.vcxproj )
IF NOT EXIST %srcMetaEnumDir%MetaEnum.vcxproj.filters ( COPY /V MetaEnum.vcxproj.filters %srcMetaEnumDir%MetaEnum.vcxproj.filters) ELSE ( COPY /V %srcMetaEnumDir%MetaEnum.vcxproj.filters MetaEnum.vcxproj.filters )
IF NOT EXIST %srcMetaEnumDir%MetaEnum.vcxproj.user ( COPY /V MetaEnum.vcxproj.user %srcMetaEnumDir%MetaEnum.vcxproj.user) ELSE ( COPY /V %srcMetaEnumDir%MetaEnum.vcxproj.user MetaEnum.vcxproj.user )
popd