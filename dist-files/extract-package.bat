@echo off
rem Extracts your own After Burner Climax XBLA package (the Xbox 360 LIVE/PIRS/CON file) into the
rem "assets" folder next to after_burner_climax.exe. Drag the package file onto this .bat.
rem Needs Python 3 (python.org - tick "Add python.exe to PATH").
cd /d "%~dp0"
if "%~1"=="" (echo Drag your After Burner Climax package file onto this .bat. & pause & exit /b 1)
where python >nul 2>nul || (echo Python 3 is required: https://www.python.org/downloads/ & pause & exit /b 1)
python tools\stfs_extract.py "%~1" assets >nul
if errorlevel 1 (echo Extraction failed - is that the After Burner Climax package? & pause & exit /b 1)
if not exist assets\default.xex (echo No default.xex found in the package - is that the game package? & pause & exit /b 1)
echo.
echo Done. Run after_burner_climax.exe to play.
pause
