#include "Q14.h"
#define MAXLEN 5
#define MAXNAMELEN 20
void print_profile(struct profile *);
void print_profile_value(struct profile);

struct name {
	char fname[MAXNAMELEN];
	char mname[MAXNAMELEN];
	char lname[MAXNAMELEN];
};

struct profile {
	long social_security_num;
	struct name full_name;
};

int Q14_4(void)
{
	struct profile profiles[MAXLEN];

	for (int i = 0; i < MAXLEN; i++)
		print_profile(&profiles[i]);

	for (int i = 0; i < MAXLEN; i++)
		print_profile_value(profiles[i]);

	return 0;
}

void print_profile(struct profile *profile)
{
	printf("%s, %s", profile->full_name.fname, profile->full_name.lname);
	if (profile->full_name.mname)
		printf("%1s.", profile->full_name.mname);
	printf(" -- %ld\n", profile->social_security_num);
}

void print_profile_value(struct profile profile)
{
	printf("%s, %s", profile.full_name.fname, profile.full_name.lname);
	if (profile.full_name.mname)
		printf("%1s.", profile.full_name.mname);
	printf(" -- %ld\n", profile.social_security_num);
}