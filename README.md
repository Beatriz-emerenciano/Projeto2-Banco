# Projeto2-Banco

Projeto desenvolvido pelas estudantes Agatha Mello e Beatriz Cristina emerenciano do curso superior de ciência da computação do Centro  universitário FEI.

### O que faz o programa?

O programa é um simulação de um sistema bancário,que realiza as operações de:

-Cadastro de clientes
-Listagem de clientes
- Apagar cliente
-Débito
-Depósito
-Transfeência
- Extrato

### lógica do programa:

Foi utilizado uma struct para armazenar os dados do clientes, nesa struct contém:

-char nome
-Long long int cpf
-Char conta
-Char senha
-Char xtrato

e funções:
 -LimparBuffer
-menu()
-Cadastro()
-ListarCliente()
-LimparBufferEntrada()
-ApagarCliente()
-Debito()
-Deposito()
-Transferencia()
-Função extrato
-Salvar()
-Carregar()

.LimparBufferEntrada: essa função tem a finalidade de limpar o buffer de entrada para que não gere comportamentos inesperados;

. Menu: A função não recebe parametros, são um conjuntos impressoes(printf) de mensagem para apresentar ao usuários as opções do sistema;

. CADASTAR: é utilizado um ponteiro que aponta para a estrutura  cliente, printf para imprimir mensagem, scanf e fgets para armazenar os dados que usuário digitou na strutrutura cliente;

. LISTAR: A função recebe o ponteiro para a estrutura clientes e um int numClientes para controle de numero de clientes cadastrados, para listar os clientes é usado um for para iterar sobre o numeClientes.

.ApagarCliente: recebe um ponteiro da estrutura clientes numClientes e long long cpf, há um for para iterar sobre os numeros de clientes se o cpf digitado pelo usário for igual ao que está cadastrado, a váriável index recebe o valor do contador i e apaga o cliente;

.DÉBITO: a função inicializa como index -1 para armazenar a posição do cliente para usar no código, se o cpf e senha(para a comparações de strings é usado o strcmp) for validados atrávez de uma iteração com o for  será realizado o débito e desconto de acordo com o tipo de conta do cliente;

.DEPÓSITO: recebe um ponteiro para a estrutura clientes, numClientes e cpf, há uma verificação de dados com um for, assim que os dsdos estiverem validados o usuário acrescenta um valor na variável sado da estrutura cliente.

.TRANSFERÊNCIA: as váriáveis index origem e index destino são iniciadas em -1, esses indices são usados para percorrer todos os clientes cadastrados onde a variável NumCliente é a quantidade total de clientes, depoois há uma verificação de cpf com o if, se o cliente i.cpf for igual do cliente origem e o destinário a variáveç index origem e index destino conterá os indices dos clientes com os cpfs correspondentes a eles para depois realizar a transferência.

.SALVAR: a função salva os dados dos clientes em um arquivo binário que recebe um vetor clientes e o pumero de clientes cadastrados e escreve em arquivo binário.

.CARREGAR: A função lê os dados do arquivo binário e os carrega de volta no vetor de clientes atualizando o número de clientes cadastrados 




