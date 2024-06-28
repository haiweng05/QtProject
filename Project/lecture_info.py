import time
from datetime import datetime
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import sys
from selenium.webdriver.edge.service import Service
import io
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python lecture_info.py <date>")
        sys.exit(1)
    date_str = sys.argv[1]
    
    driver_path = r"..\\src\\msedgedriver.exe"
    service = Service(executable_path=driver_path)
    driver = webdriver.Edge(service=service)
    driver.set_page_load_timeout(20)
    target_date = sys.argv[1]
    target_year = int(target_date.split('-')[0])
    target_month = int(target_date.split('-')[1])

    now = datetime.now()
    cur_year, cur_month = now.year, now.month
# 打开目标网页
    base_url =  "https://resource.pku.edu.cn/index.php?r=lecturepre%2Findex"
    driver.get(base_url)

    wait = WebDriverWait(driver, 10)
    date_picker = wait.until(EC.presence_of_element_located((By.ID, 'chooseDate')))

# 不要click，会打开年份选择导致下面读不到月份
# 打开日期选择器
# date_picker.click()

# 目标年份和月份


# 等待年份和月份选择器加载
    while target_year>cur_year:
       next_year_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, '.laydate-next-y')))
       next_year_button.click()
       cur_year+=1

    while target_year<cur_year:
       prev_year_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, '.laydate-prev-y')))
       prev_year_button.click()
       cur_year-=1
    
    
# 等待月份选择器加载并选择月份
    while target_month>cur_month:
      next_month_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, '.laydate-next-m')))
      next_month_button.click()
      cur_month+=1

    while target_month<cur_month:
      prev_month_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, '.laydate-prev-m')))
      prev_month_button.click()
      cur_month-=1
   

# 等待日期表格加载
    date_table = wait.until(EC.presence_of_element_located((By.XPATH, "//div[@class='layui-laydate-content']//table")))

# 选择目标日期
    date_element = date_table.find_element(By.XPATH, f".//td[@lay-ymd='{target_date}']")
    date_element.click()
# 选完日期后sleep一下等讲座信息重新加载，否则下面会读到改日期前的
    time.sleep(5)

# 等待讲座信息加载
    try:
       lectures_container = wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'ul.pre-list.lecture-list')))
    except:
       print("Timeout: Could not find the lecture list container.")
    # print(driver.page_source)
       driver.quit()
       exit(1)
# 提取讲座信息
    lectures = lectures_container.find_elements(By.CSS_SELECTOR, 'li.pre-item')
    

# 打印找到的讲座数量
    # print(f"Found {len(lectures)} lectures")
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf8')
    for lecture in lectures:
        brief_div = lecture.find_element(By.CSS_SELECTOR, 'div.brief')
        title_tag = brief_div.find_element(By.CSS_SELECTOR, 'a.show-detail')
        title = title_tag.get_attribute('title')
        speaker = brief_div.find_element(By.CSS_SELECTOR, 'span.speaker').text.replace('主讲人:', '').strip()
        time = brief_div.find_element(By.CSS_SELECTOR, 'span.time').text.replace('时间:', '').strip()

        print(f"讲座标题: {title} {speaker} {time}")

# 关闭浏览器
    driver.quit()
