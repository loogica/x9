# x9

* x9 informs you about the code inside your current folder.
* x9 is a building block to other kinds of applications

this is what x9 is today..

[![Build Status](https://secure.travis-ci.org/loogica/x9.png)](http://travis-ci.org/loogica/x9)

## Install

default procedure..

```
make
sudo make install
```

If you want to uninstall use ``make uninstall``

## Running

If there is a settings.py in your current dir:

```sh
$ cd /project/path
$ x9
Makefile/Compatible  /Makefile
Python Test module   /some_app/tests/__init__.py
Python/Django        /some_project/settings/__init__.py
Python/Requirements  /requirements.txt
```

## Supported Types

Help me! PR!

<table>
  <thead>
    <td>Project Type</td>
    <td>Filenames</td>
  </thead>
  <tbody>
    <tr>
      <td>Python/Django</td>
      <td>settings.py</td>
    </tr>
    <tr>
      <td>Python/Django</td>
      <td>settings/__init__.py</td>
    </tr>
    <tr>
      <td>Python/Lib</td>
      <td>setup.py</td>
    </tr>
    <tr>
      <td>Python Test Module</td>
      <td>tests/__init__.py</td>
    </tr>
    <tr>
      <td>Java/Maven</td>
      <td>pom.xml</td>
    </tr>
    <tr>
      <td>Makefile/Compatible</td>
      <td>Makefile</td>
    </tr>
    <tr>
      <td>Python/Requirements</td>
      <td>requirements.txt</td>
    </tr>
    <tr>
      <td>Git repository</td>
      <td>.git</td>
    </tr>
    <tr>
      <td>Hg Repository</td>
      <td>.hg</td>
    </tr>
  </tbody>
</table>

## License

BSD. Check LICENSE file.

## Contact

felipecruz@loogica.net
