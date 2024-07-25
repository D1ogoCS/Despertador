# Despertador
## Desenvolvimento de um sistema de gestão de processos na linguagem de programação C

Neste trabalho prático, o objetivo é desenvolver um sistema de gestão de processos utilizando a linguagem de programação C. O sistema deverá ser capaz de criar processos filhos a partir de um processo pai, permitindo a execução simultânea de múltiplos processos independentes. Além disso, o trabalho deve conter a implementação de conceitos fundamentais de sistemas operativos, como criação de processos, comunicação entre processos e sincronização.

### Objetivos:
- Implementar um programa concorrente em linguagem de programação C para simular um despertador
- O programa deve permitir que o utilizador defina um horário de despertar e, quando esse horário for alcançado, deve exibir uma mensagem indicando que é hora de acordar.
- Enquanto o programa estiver a aguardar o horário de despertar, deve ser capaz de executar outras tarefas concorrentemente, como por exemplo: alterar a hora de despertar, desligar ou suspender o alarme.

### Funcionalidades:
- O utilizador pode definir o horário de despertar através da entrada de dados
- O programa exibe a hora atual enquanto espera pelo horário de despertar
- Quando o horário de despertar é alcançado, o programa exibe a mensagem "Hora de acordar!"
- O programa é capaz de executar outras tarefas concorrentemente enquanto aguarda o horário de despertar como por exemplo: alterar a hora de despertar, desligar ou suspender o alarme

### Ferramentas utilizadas:
- Ubuntu: Sistema operativo baseado em Linux
- Nautilus: Gestor de ficheiros padrão do Ubuntu

### Tecnologias utilizadas:
- Linguagem C

### Descrição:

O programa possui três funções fundamentais que são:
- mostrarHoraAtual(): Possui um ciclo infinito para executar a função __menu()__ de minuto a minuto, mas a função __menu()__ só é executada se o utilizador não estiver a definir um horário de despertar
- alarme(): Possui um ciclo infinito. Foi criada uma variável do tipo *localtime*, que permite verificar se a hora atual é igual à hora que o utilizador definiu para despertar. Assim que a hora atual for igual à hora de despertar, é impresso no terminal a mensagem “Hora de acordar! Clique 9 para parar.” e se estiver a usar o código no Ubunto é também emitido um som de alerta, mas isto só acontece se o utilizador tiver as notificações sonoras ativas. Para o utilizador parar a mensagem de despertar basta digitar “9” no terminal o que fará mudar o valor da variável __dslMsg__ e por consequência interromper o alarme
- menu(): Sempre que é executada, imprime no ecrã a hora atual do sistema, assim como o menu com as funções do despertador

### Resultados:
O Ubuntu foi instalado no computador atraves do WSL(Subsistema do Windows para Linux). O WSL é um recurso do Windows que permite executar um ambiente Linux no computador com sistema operativo Windows, sem a necessidade de utilizar uma máquina virtual.

![Nautilus](https://github.com/D1ogoCS/Despertador/blob/main/imagens/ubuntu.png)

*Nautilus*

![Código no processador de texto do Ubuntu](https://github.com/D1ogoCS/Despertador/blob/main/imagens/ubuntu2.png)

*Código no processador de texto do Ubuntu*

![Menu](https://github.com/D1ogoCS/Despertador/blob/main/imagens/menu.png)

*Menu*

Se o utilizador escolher a opção “1-Definir Despertador”, consegue definir um horário de despertar para definir as horas com um valor no intervalo de 0 a 23 e os minutos com um valor no intervalo de 0 a 59. Sempre que o valor de uma destas variáveis sair do intervalo permitido, é indicado ao utilizador para o introduzir novamente o horário de despertar. Após o horário definido, a *thread* do despertador é criada e o horário escolhido para despertar é impresso no terminal e a variável __notificacaoSonora__ é também ativa.

![Definir despertador](https://github.com/D1ogoCS/Despertador/blob/main/imagens/opcao1.png)

*Definir despertador*

Se o utilizador escolher a opção “2-Desligar despertador”, a *thread* do despertador é terminada e é impresso no terminal uma mensagem a dizer que o alarme foi desligado.

![Desligar despertador](https://github.com/D1ogoCS/Despertador/blob/main/imagens/opcao2.png)

*Desligar despertador*

Se o utilizador escolher a opção “3-Silenciar Alarme” ou a opção “4-Ativar Alarme” permite escolher se as notificações estão ativas ou não e imprime no terminal a respetiva escolha.

![Silenciar alarme](https://github.com/D1ogoCS/Despertador/blob/main/imagens/opcao3.png)

*Silenciar alarme*

![Ativar alarme](https://github.com/D1ogoCS/Despertador/blob/main/imagens/opcao4.png)
 
*Ativar alarme*

Se o utilizador escolher a opção “5-Ver Despertador”, é impresso no terminal o horário de despertar definido que o utilizador escolheu.

![Ver despertador](https://github.com/D1ogoCS/Despertador/blob/main/imagens/opcao5.png)
 
*Ver despertador*
