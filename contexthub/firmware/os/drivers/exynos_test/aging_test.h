/*----------------------------------------------------------------------------
 *      Exynos SoC  -  Aging UTC
 *----------------------------------------------------------------------------
 *      Name:    timer_test.h
 *      Purpose: To implement aging-test codes
 *      Rev.:    V1.00
 *----------------------------------------------------------------------------
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __AGING_TEST_H__
#define __AGING_TEST_H__

#include <csp_common.h>
#include <csp_assert.h>
#include <csp_printf.h>
#include <timer.h>

void aging_test(void);
void aging_test_clean_up(void);

#endif
