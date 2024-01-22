<!-- 体检报告 -->
<template>
  <div>
    <el-container>
      <el-aside>
        <PeoplleList title="人员查询"></PeoplleList>
      </el-aside>
      <el-main>
        <h3 class="head">报告预览</h3>
        <div class="pdf">
          <PdfObject></PdfObject>
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
import PdfObject from '@/components/pdfobject/PdfObject.vue'
</script>

<style lang="scss" scoped>
.head {
  font-weight: bold;
}
</style>
