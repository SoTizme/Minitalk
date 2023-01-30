SNAME = server
CNAME = client

CSRCS = mandatory/client.c
SSRCS = mandatory/server.c

BSNAME = server_bonus
BCNAME = client_bonus

CSRCS_B = bonus/client_bonus.c
SSRCS_B = bonus/server_bonus.c

UTLS = src/ft_putnbr.c src/ft_atoi.c src/ft_strlen.c
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CNAME) $(SNAME)

$(SNAME) : $(SSRCS)
	$(CC) $(CFLAGS) $(UTLS) $(SSRCS) -o $(SNAME)

$(CNAME) : $(CSRCS)
	$(CC) $(CFLAGS) $(UTLS) $(CSRCS) -o $(CNAME)

bonus: $(BCNAME) $(BSNAME)

$(BSNAME) : $(SSRCS_B)
	$(CC) $(CFLAGS) $(UTLS) $(SSRCS_B) -o $(BSNAME)

$(BCNAME) : $(CSRCS_B)
	$(CC) $(CFLAGS) $(UTLS) $(CSRCS_B) -o $(BCNAME)

clean:
	$(RM) $(SNAME) $(CNAME) $(BSNAME) $(BCNAME)

fclean: clean

re: fclean all

.PHONY : clean fclean re bonus all