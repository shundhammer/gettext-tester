#!/usr/bin/env ruby
#
# encoding: utf-8
#
# Extract the messages with
#
#   rxgettext -o hello-ruby.pot hello-ruby.c

class HelloRuby
  def initialize
    textdomain "hello-ruby"
  end

  def run
    say_hello
    talk
    weird_format
  end

  def say_hello
    printf(_("Hello, world!\n"))
    puts(_("How are you today?"))
  end

  def talk
    vars =
    {
      bar:  "bar",
      foo:  "foo",
      truth: 42
    }

    printf(_("printf-like parameters %s and %s\n"), "foo", "bar")
    # printf(_("Numbered printf parameters %2$s and %1$s\n"), "bar", "foo")

    puts(_("sformat-like message with parameters %1 and %2", "foo", "bar"))

    puts(_("Named parameters %{foo} and %{bar}: %{truth}") % vars)
    puts(_("Named parameters %<foo>s and %<bar>s: %<truth>d") % vars)
  end

  def weird_format
    # xgettext:c-format
    puts(_("Weird format: %1 %2"))
  end

  def _(*msg)
    msg.first
  end

  def textdomain(_domain)
    # NOP
  end
end

if __FILE__ == $0 # if called as a standalone command
  HelloRuby.new.run
end
