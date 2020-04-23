# gettext-tester

Simple examples demonstrating consistency checks of translations with the GNU
gettext tools.

This is really little more than a blown-up "Hello World" program that uses
gettext for translations.

The program itself does not do much; it's just a showcase for using the gettext
tools.

There are some very simple scripts here for invoking the various gettext tools:

- create-pot

  This creates a .pot file, i.e. it invokes `xgettext` to extract the
  translatable messages from the C source.

- check-po

  This uses `msgfmt` to check a translation file (a .po file) for consistency
  and to convert it to the corresponding .mo file.

  Call it without any parameters to use `hello-01.po` or with the .po file that
  you want checked:

      check-po

      check-po my-translations.po
      

- build

  This compiles and links the example program. This is mostly useful to ensure
  that it's syntactially correct.
