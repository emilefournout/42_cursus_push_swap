/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_useless_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:08:14 by efournou          #+#    #+#             */
/*   Updated: 2022/07/16 20:13:45 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	detect_stack_empty(char *instruction, int count_push_a,
		int count_push_b, int index)
{
	if (instruction[index] == 1 && count_push_b <= count_push_a)
		return (1);
	else if ((instruction[index] == 4 || instruction[index] == 5
			|| instruction[index] == 7
			|| instruction[index] == 8 || instruction[index] == 10
			|| instruction[index] == 11) && (count_push_a >= count_push_b))
		return (1);
	return (0);
}

static int	detect_double_swap(char *instruction, int index)
{
	if (instruction[index] == 3 && (instruction[index + 1] == 3
			|| instruction[index + 1] == 5))
		return (1);
	else if (instruction[index] == 4 && (instruction[index + 1] == 4
			|| instruction[index + 1] == 5))
		return (1);
	else if (instruction[index] == 5 && (instruction[index + 1] <= 5
			&& instruction[index + 1] >= 3))
		return (1);
	return (0);
}

static int	detect_double_shift(char *instruction, int index)
{
	if (instruction[index] == 6 && (instruction[index + 1] == 9
			|| instruction[index + 1] == 11))
		return (1);
	else if (instruction[index] == 7 && (instruction[index + 1] == 10
			|| instruction[index + 1] == 11))
		return (1);
	else if (instruction[index] == 8 && (instruction[index + 1] >= 9
			&& instruction[index + 1] <= 11))
		return (1);
	else if (instruction[index] == 9 && (instruction[index + 1] == 6
			|| instruction[index + 1] == 8))
		return (1);
	else if (instruction[index] == 10 && (instruction[index + 1] == 7
			|| instruction[index + 1] == 8))
		return (1);
	else if (instruction[index] == 11 && (instruction[index + 1] >= 6
			&& instruction[index + 1] <= 8))
		return (1);
	return (0);
}

static int	detect_problem(char *instruction, int count_push_a,
		int count_push_b, int index)
{
	if (detect_stack_empty(instruction, count_push_a, count_push_b, index) == 1)
		return (1);
	else if (detect_double_swap(instruction, index) == 1)
		return (1);
	else if (detect_double_shift(instruction, index) == 1)
		return (1);
	return (0);
}

int	detect_useless_instruction(char *instruction)
{
	int	index;
	int	count_push_a;
	int	count_push_b;

	count_push_b = 0;
	count_push_a = 0;
	index = 0;
	if (instruction[0] == 1)
		return (1);
	while (instruction[index] != '\0')
	{
		if (detect_problem(instruction, count_push_a, count_push_b, index) == 1)
			return (1);
		if (instruction[index] == 1)
			count_push_a++;
		else if (instruction[index] == 2)
			count_push_b++;
		index++;
	}
	if (count_push_a != count_push_b)
		return (1);
	return (0);
}
