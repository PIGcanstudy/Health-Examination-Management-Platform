<!-- 单位报告 -->
<template>
  <div>
    <el-container>
      <el-aside width="200px">
        <PeoplleList title="报告查询"></PeoplleList>
      </el-aside>
      <el-main>
        <div class="form">
          <h3 class="head">报告信息</h3>
          <div>
            <el-form :model="formData" :inline="true">
              <el-form-item v-model="formData.num" label="报告编号">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="体检类型">
                <el-select v-model="formData.checkupType" placeholder="更多操作">
                  <el-option label="刷新" value="type1"></el-option>
                  <el-option label="批量删除" value="type2"></el-option>
                  <el-option label="导出本页数据" value="type3"></el-option>
                </el-select>
              </el-form-item>
              <el-form-item label="体检单位">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="委托单位">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="报告日期">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="体检人数">
                <el-input placeholder="请输入" clearable class="input" />
              </el-form-item>
              <el-form-item label="体检项目">
                <el-input placeholder="请输入" clearable type="textarea" />
              </el-form-item>
              <el-form-item label="评论依据">
                <el-input placeholder="请输入" clearable type="textarea" />
              </el-form-item>
              <el-form-item label="体检结论与处理意见">
                <el-input placeholder="请输入" clearable type="textarea" />
              </el-form-item>
            </el-form>
          </div>
        </div>

        <div class="tables">
          <Head name="报告信息">
            <el-button type="primary">导出选中表格</el-button>
          </Head>
          <el-tabs v-model="activeName" @tab-click="handleClick">
            <el-tab-pane label="体检人员汇总表" name="first">
              <BaseDataList :useFixed="false"></BaseDataList>
            </el-tab-pane>
            <el-tab-pane label="复查人员汇总表" name="second">
              <BaseDataList :useFixed="false"></BaseDataList>
            </el-tab-pane>
            <el-tab-pane label="复查结果汇总表" name="third">
              <BaseDataList :useFixed="false"></BaseDataList>
            </el-tab-pane>
          </el-tabs>
        </div>

        <div class="btns">
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
import { ref } from 'vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'


const formData = ref(
  {

  }
)
</script>

<style lang="scss" scoped>
.head {
  font-weight: bold;
}

// .input {
//   --el-input-width: 400px;
// }
</style>
