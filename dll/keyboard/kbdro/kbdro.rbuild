<?xml version="1.0"?>
<!DOCTYPE module SYSTEM "../../../tools/rbuild/project.dtd">
<module name="kbdro" type="keyboardlayout" entrypoint="0" installbase="system32" installname="kbdro.dll" allowwarnings="true">
	<importlibrary definition="kbdro.def" />
	<include base="ntoskrnl">include</include>
	<define name="_DISABLE_TIDENTS" />
	<define name="_WIN32_WINNT">0x0500</define>
	<file>kbdro.c</file>
	<file>kbdro.rc</file>
</module>
