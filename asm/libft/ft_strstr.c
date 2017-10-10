/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:35:40 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/05 13:06:04 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j])
			{
				if (big[i + j] != little[j])
					break ;
				j++;
				if (little[j] == '\0')
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (0);
}
