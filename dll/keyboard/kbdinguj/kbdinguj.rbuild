<?xml version="1.0"?>
<!DOCTYPE module SYSTEM "../../../tools/rbuild/project.dtd">
<module name="kbdinguj" type="keyboardlayout" entrypoint="0" installbase="system32" installname="kbdinguj.dll" allowwarnings="true">
	<importlibrary definition="kbdinguj.def" />
	<include base="ntoskrnl">include</include>
	<define name="_DISABLE_TIDENTS" />
	<define name="_WIN32_WINNT">0x0500</define>
	<file>kbdinguj.c</file>
	<file>kbdinguj.rc</file>
</module>
