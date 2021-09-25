/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
  char *buf, *p, *method;
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  int n1=0, n2=0;

  // extract the two arguments
  if((buf = getenv("QUERY_STRING")) != NULL) {
    p = strchr(buf, '&');
    // strchr 문자열 내 문자가 있는지 없는지 찾아보는 함수
    *p = '\0'; //uri & 뒤 모두 제거

    // buf = strchr(buf, '='); //""으로 하면 " \0"로 인식함 // ''으로 해주어야함
    // p = strchr(p+1, '=');
    // strcpy(arg1, buf+1); // '\0'으로 string 끝을 찾아서, 해당 string을 arg1에 복사
    // strcpy(arg2, p+1);
    // n1 = atoi(arg1); //
    // n2 = atoi(arg2);

    sscanf(buf, "first=%d", &n1);
    sscanf(p+1, "second=%d", &n2);

  }

  // method = getenv("REQUEST_METHOD");

  // make the response body
  sprintf(content, "QUERY_STRING=%s", buf);
  sprintf(content, "Welcome to add.com: ");
  sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
  sprintf(content, "%sThe answer is : %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);
  sprintf(content, "%sThanks for visiting!\r\n", content);

  // generate the HTTP response
  printf("Connection : close\r\n");
  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");
  printf("%s", content);
  fflush(stdout);

  exit(0);
}
/* $end adder */