<!-- 团检订单 -->
<template>
  <el-container style="height: 100%">
    <el-aside width="250px">
      <PeopleList style="height: 100%; width: 100%" />
    </el-aside>
    <el-main style="">
      <!-- 按钮 -->
      <el-row style="margin-bottom: 15px">
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
      </el-row>

      <!-- 表单 -->
      <el-form :inline="true" :model="formInline" class="demo-form-inline" style="padding: 0 25px">
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="Approved by">
          <el-input placeholder="Approved by" clearable />
        </el-form-item>
      </el-form>

      <!-- 体检项目 -->
      <div class="alter" style="display: flex; padding-bottom: 5px">
        <span>体检项目</span>
        <el-button type="primary" size="small">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary" size="small">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
      </div>
      <!-- 分页标签 -->
      <el-tabs type="border-card" style="margin-bottom: 15px;">
        <el-tab-pane label="男">
          <ActionTable :tableData="tableData1" />
        </el-tab-pane>
        <el-tab-pane label="女">
          <ActionTable :tableData="tableData2" />
        </el-tab-pane>
      </el-tabs>

      <!-- 体检人员 -->
      <div class="alter" title="success alert">
        <span>体检人员</span>
      </div>
      <!-- 表格 -->
      <el-table :data="tableData1" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
        <el-table-column type="selection" width="60" />
        <el-table-column prop="name" label="姓名" />
        <el-table-column prop="result" label="性别" />
        <el-table-column prop="unit" label="证件号码" />
        <el-table-column prop="reference" label="年龄" />
      </el-table>
    </el-main>
  </el-container>
</template>

<script setup>
import ActionTable from '@/components/details/ActionTable.vue'
import PersonInfo from '@/components/personinfo/PersonInfo.vue'
import PeopleList from '@/components/peoplelist/PeopleList.vue'

const tableData1 = [
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '3',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '4',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '5',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '6',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  }
]
</script>

<style lang="scss" scoped>
.alter {
  background-color: #f0faff;
  border: 1px solid #b7e0ff;
  padding: 6px;
  border-radius: 5px;

  span {
    color: #000;
    font-weight: 600;
    font-size: small;
    margin-right: 15px;
  }
}
</style>
