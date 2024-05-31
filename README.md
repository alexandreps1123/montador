-- Montador

 *** 2 modos de execução
 1°
   *** ./montador -p myfile.asm
    
    *** deve gerar um arquivo pre-procressado myfile.pre.
 2° 
   *** ./montador -o myfile.pre
    
    *** deve gerar um arquivo myfile.obj
    
*** O montador nao deve ser sensível ao caso. 
*** Deve poder aceitar espaços em branco e tabulações em qualquer lugar do código. 
*** Deve aceitar quebra de linhas entre rótulo e operação. 
*** Deve aceitar comentário em qualquer parte do código, o comentário é indicado pelo caracter “;”.
*** Comando copy os argumentos estarão separados por vírgula "," SEM espaço.

****** Pre-processamento

*** O arquivo de entrada pode ter EQU e IF. 
*** As diretivas EQU sempre ficaram nas primeiras linhas do codigo. 
*** As diretivas IF podem estar em qualquer lugar. 
*** O pre processador deve avaliar e retirar essas diretivas conforme visto em sala de aula.
*** A diretiva CONST deve aceitar positivos, negativos e hexa no formato 0x (ex: 0x12).
*** Pode dar rótulo seguido de dois pontos e ENTER. O rótulo é considerado como da linha seguinte
*** O comentário deve ser removido no pré-processamento de EQU e IF
*** Assumir que os SPACES E CONST sempre estao no final
*** A saida do pre processador deve ser um arquivo de texto SEM comentários, EQU e IF. 

****** Montagem

*** O arquivo de entrada pode ter EQU e IF. 
*** As diretivas EQU sempre ficaram nas primeiras linhas do codigo. 
*** As diretivas IF podem estar em qualquer lugar. 
*** O pre processador deve avaliar e retirar essas diretivas conforme visto em sala de aula.
*** A diretiva CONST deve aceitar positivos, negativos e hexa no formato 0x (ex: 0x12).
*** Pode dar rótulo seguido de dois pontos e ENTER. O rótulo é considerado como da linha seguinte
*** O comentário deve ser removido no pré-processamento de EQU e IF
*** Assumir que os SPACES E CONST sempre estao no final
*** A saida do pre processador deve ser um arquivo de texto SEM comentários, EQU e IF. 
