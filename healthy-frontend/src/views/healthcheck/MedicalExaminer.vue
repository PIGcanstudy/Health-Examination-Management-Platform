<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-22 18:16:25
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-01-23 22:58:54
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\healthcheck\MedivalExaminer.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!-- 体检人员 -->
<template>
  <el-container style="height: 100%" class="container">
    <el-aside style="width: 20%">
      <!-- 还没改名字：团检订单 -->
      <PeopleList />
    </el-aside>

    <div class="collapse" style="height: 100%; line-height: 100vh; margin: 4px">
      <el-icon><ArrowLeft /></el-icon>
    </div>

    <el-main class="main">
      <!-- 中间部分：团检人员 -->
      <div class="center-part">
        <el-card class="title-operation">
          <el-row>
            <div class="title" style="margin-right: 15px; font-weight: 550">团检人员</div>
            <el-button type="primary">
              <el-icon><Upload /></el-icon>
              导入
            </el-button>
            <el-button type="primary">
              <el-icon><CirclePlus /></el-icon>
              新增
            </el-button>
            <el-button type="primary">
              <el-icon><Download /></el-icon>
              导出
            </el-button>
            <el-button type="primary">
              <el-icon><Download /></el-icon>
              导出订单
            </el-button>
          </el-row>
        </el-card>
        <div class="test-code" style="height: 93%">
          <el-card style="height: 100%" shadow="hover">
            <el-tabs type="border-card">
              <el-tab-pane label="男">
                <el-table :data="personInfo" border style="width: 100%; margin-top: 10px">
                  <el-table-column type="selection" width="55" />
                  <el-table-column prop="name" label="姓名" />
                  <el-table-column prop="result" label="性别" />
                  <el-table-column prop="reference" label="证件号码" />
                  <el-table-column prop="unit" label="年龄" />
                  <el-table-column prop="prompt" label="操作" />
                </el-table>
              </el-tab-pane>
              <el-tab-pane label="女">
                <el-table :data="personInfo" border style="width: 100%; margin-top: 10px">
                  <el-table-column type="selection" width="55" />
                  <el-table-column prop="name" label="姓名" />
                  <el-table-column prop="result" label="性别" />
                  <el-table-column prop="reference" label="证件号码" />
                  <el-table-column prop="unit" label="年龄" />
                  <el-table-column prop="prompt" label="操作" />
                </el-table>
              </el-tab-pane>

              <!-- 分页器 -->
              <el-pagination
                v-model:current-page="currentPage4"
                v-model:page-size="pageSize4"
                style="margin-top: 14px"
                :page-sizes="[10, 20, 50]"
                small="small"
                layout="->, total, prev, pager, next,sizes,  jumper"
                :total="0"
                @size-change="handleSizeChange"
                @current-change="handleCurrentChange"
              />
            </el-tabs>
          </el-card>
        </div>
      </div>

      <!-- 右边部分：订单信息 -->
      <div class="right-part" style="position: absolute; top: 0; right: 0; width: 40%; height: 100%">
        <el-card class="title-bar" body-style="font-weight: 700">订单信息</el-card>
        <el-card style="height: 30%" shadow="hover">
          <el-form :inline="true" :model="formInline" label-width="70px" style="font-size: 12px" disabled="true">
            <el-form-item label="体检单位" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="体检类型" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="体检时间" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="套餐金额" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="订单编号" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="签订时间" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="检查人数" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="销售人员" style="width: 155px">
              <el-input />
            </el-form-item>
          </el-form>
        </el-card>
        <el-card class="title-bar" body-style="font-weight: 700" style="margin-top: 6px">团体项目</el-card>
        <div style="height: 55%">
          <el-card style="height: 100%" shadow="hover">
            <el-table :data="personInfo" border style="width: 100%">
              <el-table-column prop="project" label="体检项目" />
              <el-table-column prop="originalPrice" label="原价(元)" />
              <el-table-column prop="discount" label="折扣(100%)" />
              <el-table-column prop="discountPrice" label="折扣价(元)" />
            </el-table>

            <!-- 分页器 -->
            <el-pagination
              v-model:current-page="currentPage4"
              v-model:page-size="pageSize4"
              style="margin-top: 14px"
              :page-sizes="[10, 20, 50]"
              small="small"
              layout="->, total, prev, pager, next"
              :total="0"
              @size-change="handleSizeChange"
              @current-change="handleCurrentChange"
            />
          </el-card>
        </div>
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import PeopleList from '@/components/peoplelist/PeopleList.vue'
import { Upload, CirclePlus, Download, ArrowLeft } from '@element-plus/icons-vue'
// import { ref } from 'vue'
// import { defineProps, defineEmits } from 'vue'

// const props = defineProps({
//   usePagination: {
//     type: Boolean,
//     default: true
//   }
// })
// const emits = defineEmits(['updateTableData'])

// // 分页数据的处理逻辑
// const paginationData = ref({
//   currentPage: 1,
//   pageSize: props.pageSizes ? props.pageSizes[0] : 10
// })

// const handleSizeChange = (pageSize) => {
//   // 当前页的数据容量改变，重置页码为1(因页面大小限制，每页条数固定值为10)
//   paginationData.value.currentPage = 1
//   // 传入当期那页面的容量大小和当前页面
//   emits('updateTableData', pageSize, paginationData.value.currentPage)
// }
// const handleCurrentChange = (currentPage) => {
//   paginationData.value.currentPage = currentPage
//   // 传入当前页码容量(默认值10)和当前页码
//   emits('updateTableData', paginationData.value.pageSize, currentPage)
// }

// defineExpose({
//   paginationData
// })
</script>

<style lang="scss" scoped>
.container {
  width: 100%;
  height: 100%;
  overflow: hidden;
}
.main {
  display: flex;
  position: relative;
}
.center-part {
  height: 100%;
  position: absolute;
  top: 0;
  left: 0;
  width: 59%;
  align-items: center;
  justify-content: center;
  align-items: center;
}
.title-operation {
  height: 7%;
  display: flex;
  align-items: center;
  background-color: #f0faff;
  border: 1px solid #abdcff;
}
.title-bar {
  height: 7%;
  font-weight: 900;

  display: flex;
  justify-content: center;
  align-items: center;
  background-color: #f0faff;
  border: 1px solid #abdcff;
}
</style>
