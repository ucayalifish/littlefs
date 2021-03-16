#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "acl_mgr.h"
#include "card_format.h"
#include "crc.h"
#include "security_regions_mgr.h"
#include "storage_mgr.h"

#define IP_ADDR_1 0xc614a8c0U
#define IP_ADDR_2 0xc814a8c0U
#define IP_ADDR_3 0xce14a8c0U
#define IP_ADDR_4 0xd314a8c0U

static unsigned adresses_[4] = {IP_ADDR_1, IP_ADDR_2, IP_ADDR_3, IP_ADDR_4};

static void polulate_sas_regions_(void)
{
  for (int i = 0; i < TOTAL_BUTTONS; ++i)
    {
      ip4_addr_t const addr   = {.addr=adresses_[rand() % 4]};
      uint8_t const    region = rand() % 64;
      uint8_t const    button = rand() % 32;
      add_region_entry(i, addr, region, button);
    }
}

static void populate_tables_(void)
{
  polulate_sas_regions_();

}

static void store_all_tables_(void)
{
  int r = persist_region_map();
  r = r != sizeof(uint32_t) ? LOGIC_FS_ERR : 0;
  printf("\tSAS regions saved: %d\n", r);
  assert(r==0);
}

static void restore_all_tables_(void)
{
  int r = restore_region_map();
  printf("\tSAS regions restored: %d\n", r);
  assert(r==0);
}

int main(void)
{
  srand(time(NULL));

  populate_tables_();

  int result = create_ram_flash();

  printf("RAM flash emulation created: %d\n", result);

  result = mount_file_system();

  printf("LittleFS mounted: %d\n", result);

  for(int run = 1; run < 10001; ++run)
    {
      printf("Test run %d\n", run);
      store_all_tables_();

      restore_all_tables_();
    }

  result = destroy_ram_flash();

  printf("RAM flash emulation destroyed: %d\n", result);

  return 0;
}
