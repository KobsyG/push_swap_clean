all:
		make -C libft
		make -C srcs
		make -C srcs/push_swap
		# make -C srcs/checker
		cp srcs/push_swap/push_swap .
		# cp srcs/checker/checker .

clean:
		make clean -C libft
		make clean -C srcs
		make clean -C srcs/push_swap
		# make clean -C srcs/checker

fclean:	clean
		make fclean -C libft
		make fclean -C srcs
		make fclean -C srcs/push_swap
		# make fclean -C srcs/checker
		# rm checker
		rm push_swap

re:		fclean all