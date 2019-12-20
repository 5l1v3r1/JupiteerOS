global idt_flush

idt_flush:          ; from: http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
  mov eax, [esp+4]
  lidt [eax]
  ret
